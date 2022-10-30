#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=1e6+30,mod = 1e9+7,inf=1e18;
int pai[N];
int main(){
    ll n, m, p;
    string com,c="";
    list <pair<int,char> > s;
    cin >> n >> m >> p;
    rep(i,0,n){
        char x;
        cin >> x;
        s.pb(mp(i,x));
        c+=x;
    }
    stack<pair<int,char> > st;
    rep (i,0,n){
        if (!st.empty() && st.top().Y == '(' && c[i] == ')'){
            pai[st.top().X] = i;
            pai[i] = st.top().X;
            st.pop();
        }
        else st.push(mp(i,c[i]));
    }
    list <pair<int, char> > :: iterator it = s.begin();
    p--;
    advance(it,p);
    cin >> com;
    rep (i,0,m){
        if (it == s.end()) it--;
        if (com[i] == 'L'){
            if (it != s.begin()){
                it--;
            }
        }
        if (com[i] == 'R'){
            it++;
            if (it == s.end()){
                it--;
            }
        }
        if (com[i] == 'D'){
            int it2=pai[(*it).X];
  //          debug(it2);
    //        debug((*it).X);
      //      if (i == 2) cout<<(*s.begin()).X;
            if ((*it).Y == ')'){
                bool f=0;
                while (!s.empty() && (*it).X >= it2){     
                    //debug(it2);
                    if (it != s.begin()){
                        it = s.erase(it);
                        if (it != s.begin()) it--;
               //         debug((*it).X);debug(i);
                    }
                    else{
                        s.pop_front();
                        it = s.begin();
                        f=1;
                        debug((*it).X); debug(i);
                        break;
                    }
                }
                if (it != s.end() && !f) it++;

//                debug((*it).X);
            }
            else{
                while (!s.empty() && (*it).X <= it2){
                    //debug((*it).X); debug((*it).Y);
                    if (it != s.end()){
                       // debug((*it).X);
                        it = s.erase(it);
                    }
                    else{
                        it--;
                        break;
                        s.pop_front();
                        it = s.begin();
                    }
                }
            }
        }
    }
    for (it=s.begin(); it != s.end(); it++) cout << (*it).Y;
}