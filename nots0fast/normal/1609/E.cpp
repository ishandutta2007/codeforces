#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf =  (1<<30);
ll modulo = pow(10,9) + 7;


#define MAX 300'010

const bool debug = 0;

ll mn[MAX][13];
ll tr[13][13];
vector<ll> valids;

string inp;

vector<string> all({"a", "ab", "b", "bc", "c"});
// min cost to make the current sequence 
// [0] = "a", [1] = "ab", [2] = "b", [3] = "bc", [4] = "c"

void getAll(ll bt, vector<string>& ans){
      ans.pb("");
      fori((ll)all.size()){
            if((1<<i) & bt){
                  ans.pb(all[i]);
            }
      }
}

ll curbit(string& a){
      ll n = a.length();
      ll bt = 0;
      fori(n){
            if(i + 2 < n && a[i] == 'a' && a[i+1] == 'b' && a[i+2] == 'c'){
                  return inf;
            }
            forj((ll)all.size()){
                  ll ln = all[j].length();
                  bool gg = 1;
                  fork(ln){
                        if(i + k >= n || all[j][k]!=a[i+k]){
                              gg = 0;
                              break;
                        }
                  }
                  if(gg){
                        bt |= (1<<j);
                  }
            }
      }
      return bt;
}

void pull(ll hd){
      fori(13){
            mn[hd][i] = inf;
      }
      ll hd1 = 2*hd, hd2 = 2*hd+1;
      fori(13){
            forj(13){
                  ll wh = tr[i][j];
                  if(wh >= inf){
                        continue;
                  }
                  mn[hd][wh] = min(mn[hd][wh], mn[hd1][i] + mn[hd2][j]);
            }
      }
}

void initwith(ll hd, char& f){
      fori(13){
            mn[hd][i] = inf;
      }
      ll id1 , id2 , id3 ;
      fori(13){
            if(valids[i] == (1<<0)){
                  id1 = i;
            }
            else if(valids[i] == (1<<2)){
                  id2 = i;
            }
            else if(valids[i] == (1<<4)){
                  id3 = i;
            }
      }
      
      
      mn[hd][id1] = 1;
      mn[hd][id2] = 1;
      mn[hd][id3] = 1;
      if(f == 'a'){
            mn[hd][id1] = 0;
      }
      else if(f == 'b'){
            mn[hd][id2] = 0;
      }
      else if(f=='c'){
            mn[hd][id3] = 0;
      }
}

void init(ll hd, ll l, ll r){
      if(l == r){
            initwith(hd, inp[l]);
            return;
      }
      init(hd*2, l, (l+r)/2);
      init(hd*2+1, (l+r)/2+1, r);
      pull(hd);
}

void upd(ll hd, ll l, ll r, ll id){
      if(id < l || r < id){
            return;
      }
      if(l == r){
            initwith(hd, inp[id]);
            if(debug){
                  cout<<"we updated "<<l<<" "<<r<<endl;
                  cout<<"now it is "<<endl;
                  fori(13){
                        cout<<mn[hd][i]<<' ';
                  }
                  cout<<endl;
            }
            return;
      }
      upd(2*hd, l, (l+r)/2, id);
      upd(2*hd+1, (l+r)/2 + 1, r, id);
      pull(hd);
      if(debug){
            cout<<"we pulled "<<l<<" "<<r<<endl;
            cout<<"now it is "<<endl;
            fori(13){
                  cout<<mn[hd][i]<<' ';
            }
            cout<<endl;
      }
      
}

void deal(){
      fori(1<<5){
            if(i & (1<<1)){
                  if(!(i & (1<<0)) || !(i & (1<<2))){
                        continue;
                  }
            }
            if(i & (1<<3)){
                  if(!(i&(1<<2)) || !(i&(1<<4))){
                        continue;
                  }
            }
            valids.pb(i);
      }
      
      fori((ll)valids.size()){
            forj((ll)valids.size()){
                  vector<string> a1, a2;
                  ll bt1 = valids[i], bt2 = valids[j];
                  getAll(bt1, a1), getAll(bt2, a2);
                  ll overall = 0;
                  for(auto& el1 : a1){
                        for(auto& el2 : a2){
                              string cur = el1 + el2;
                              overall |= curbit(cur);
                        }
                  }
                  ll lz = -1;
                  fork((ll)valids.size()){
                        if(valids[k] == overall){
                              lz = k;
                        }
                  }
                  if(overall >= inf){
                        lz = inf;
                  }
                  tr[i][j] = lz;
            }
      }
      
      if(debug){
            cout<<valids.size()<<'\n';
            
            fori(13){
                  cout<<bitset<20>(valids[i])<<endl;
            }
            cout<<endl<<endl<<endl;
      }
      
      ll n, q;
      cin>>n>>q>>inp;
      init(1, 0, n-1);
      
      forl(q){
            ll id;
            char f;
            cin>>id>>f;
            --id;
            inp[id] = f;
            upd(1, 0, n-1, id);
            
            ll ans = inf;
            fori(13){
                  ans = min(ans, mn[1][i]);
            }
            if(!debug){
                  cout<<ans<<'\n';
            }
            else{
                  cout<<endl<<endl<<endl;
            }
      }
      
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}