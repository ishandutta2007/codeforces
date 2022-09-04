// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}

long double eps=1e-8;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){
    return uniform_int_distribution<int>(0, n)(rng);
}
double drnd(){
    return (double)(rnd(INT_MAX))/INT_MAX;
}
const ll MOD=1e9+7;
const int N=2100000;

void shuffle(vec &x){
    int n=x.size();
    rep3(i,n-1,1){
        swap(x[i],x[rnd(i-1)]);
    }
}

vec id;
int cont=0;
bool ask(int k,vec x){
    cont++;
    if(k==0)return false;
    cout<<"? "<<k<<" ";
    for(auto e:x)cout<<e<<" ";
    cout<<endl;
    cout.flush();
    // int sum=0;
    // for(auto e:x)sum+=id[e-1];
    // return sum%k == 0;
    bool f;cin>>f;
    return f;
}
int __gcd(int x,int y){
    if(x==0)return y;
    else return __gcd(y%x,x);
}
int inv[810],p[810];
main(){
    int n=in();
    rep(i,n)id.pb(i+1);
    do{shuffle(id);}while(id[0]>n/2);

    if(n==2) {
        cout<<"! 1 2\n";
        cout.flush();
        return 0;
    }
    // 3*5*7*8 > 800
    // 1~9
    vector<int> s;
    rep2(i,1,n)s.emplace_back(i);
    shuffle(s);
    set<int> nex;
    for(auto e:s)nex.insert(e);
    int cnt=0;
    rep(i,n){
        auto tmp=s;
        tmp.erase(tmp.begin()+i);
        if(ask(n-1,tmp)){
            if(cnt){
                inv[1]=s[i];
                p[s[i]]=1;
            }
            else{
                inv[n]=s[i];
                p[s[i]]=n;
            }
            nex.erase(s[i]);
            cnt++;
        }
        if(cnt==2)break;
    }
    s=vec();
    for(auto e:nex)s.pb(e);
    rep2(t,2,8){
        shuffle(s);
        set<int> next;
        for(auto e:s)next.insert(e);
        int cnt=0;
        rep(i,s.size()){
            auto tmp=s;
            tmp.erase(tmp.begin()+i);
            if(ask(tmp.size(),tmp)){
                cnt++;
                next.erase(s[i]);
                if(ask(2,{inv[1],s[i]}) ^ (t&1) == 0){
                    inv[t]=s[i];
                    p[s[i]]=t;
                    if(t==8)break;
                }
                else{
                    inv[n+1-t]=s[i];
                    p[s[i]]=n+1-t;
                    if(t==8){
                        rep2(i,1,n){
                            if(p[i]){
                                p[i]=n+1-p[i];
                                inv[p[i]]=i;
                            }
                        }
                        break;
                    }
                }
                if(cnt==2)break;
            }
        }
        if(s.size()==0)break;
        vec ss;
        for(auto e:next)ss.pb(e);
        s=ss;
    }
    vec m;
    int mi=100,ans;
    rep(mask,1<<8){
        int tmp=1,sum=0;
        rep(j,8){
            if(mask & (1<<j)){
                tmp=(tmp*(j+1)/__gcd(tmp,j+1));
                sum+=j+2;
            }

        }
        if(tmp>=n and chmin(mi,sum))ans=mask;
    }
    rep(j,10){
        if(ans & (1<<j)) m.pb(j+1);
    }
    // cout<<"passed\n";
    // print(m);
    auto rem=vec2(n+1,8);
    vec res;
    rep2(i,9,n-8)res.pb(i);
    if(s.size()==0){
        goto end;
    }
    rep(i,m.size()){
        int mod=m[i];
        if(m[i]==8){
            rep2(j,1,n){
                if(p[j])continue;
                for(mod = 2;mod<=8;mod*=2){
                    vec tmp;
                    rep2(jj,1,mod){
                        tmp.pb(inv[jj]);
                    }
                    if(mod==2){
                        tmp[1]=j;
                    }
                    if(mod==4){
                        if(rem[j][i]) tmp[0]=j;
                        else tmp[3]=j;
                    }
                    if(mod==8){
                        if(rem[j][i]==0) tmp[7]=j;
                        else tmp[rem[j][i]-1]=j;
                    }
                    int T=ask(tmp.size(),tmp);
                    int sum=(mod+1)*mod/2 - 2;
                    // for(auto e:tmp)cout<<id[e-1]<<" ";cout<<":";
                    if( T ) rem[j][i]+=mod/2;
                }
                vec prob;
                for(auto e:res){
                    bool flag=true;
                    rep(k,i+1){
                        if(rem[j][k] != e%m[k]) flag=false;
                    }
                    if(flag)prob.pb(e);
                }
                // cout<<(rem[j][i] )<<" "<<id[j-1] %8 <<endl;
                if(prob.size()==1){
                    p[j]=prob[0];
                    rep(i,res.size()){
                        if(res[i]==prob[0]){res.erase(res.begin()+i);break;}
                    }
                }
            }
            continue;
        }
        vec t;
        rep2(j,1,mod)t.pb(inv[j]);
        rep2(j,1,n){
            if(p[j])continue;
            vector<pair<int,vec>> q;
            rep(k,mod){
                vec tmp=t;
                tmp[k]=j;
                int sum=0;
                rep2(iii,1,mod)if(iii!=k+1)sum+=iii;
                sum%=mod;
                sum=(mod-sum)%mod;
                // if(m[i] != 8 || (sum+rem[j][i])%(c/2))
                q.pb({sum,tmp});
                // if(k==mod-1 || ask(tmp.size(),tmp)){
                //     rem[j][i]=sum;
                //     break;
                // }
            }
            for(auto p:q){
                auto tmp=p.se;
                if(p==q.back() || ask(tmp.size(),tmp)){
                    rem[j][i]+=p.fi;
                    break;
                }
            }
            vec prob;
            for(auto e:res){
                bool flag=true;
                rep(k,i+1){
                    if(rem[j][k] != e%m[k]) flag=false;
                }
                if(flag)prob.pb(e);
            }
            if(prob.size()==1){
                p[j]=prob[0];
                rep(i,res.size()){
                    if(res[i]==prob[0]){res.erase(res.begin()+i);break;}
                }
            }
        }
        // if(m[i]==8 and c!=8)c*=2,i--;
    }
    // rep2(i,1,n){
    //     rep(j,m.size()){
    //         cout<<rem[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    rep2(i,1,n){
        if(p[i])continue;
        rep2(j,1,n){
            bool flag=true;
            rep(k,m.size()){
                if(j%m[k] != rem[i][k]) flag=false;
            }
            if(flag) p[i]=j;
        }
    }
    end:
        if(p[1]>n/2){
            rep2(i,1,n){
                p[i]=n+1-p[i];
            }
        }
        cout<<"! ";
        rep2(i,1,n)cout<<p[i]<<" ";
        cout<<endl;
        cout.flush();
        // cout<<"! ";
        // print(id);
        // print(m);
        // cout<<n*18-cont<<endl;
    ;
}