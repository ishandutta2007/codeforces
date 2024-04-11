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
const long long int N=4e6+30,mod = 1e9+7,inf=1e18;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    //debug(n);
    ll p1=0,p2=n-1;
    while (p1 < n && s[p1] == ')') p1++;
    while (p2 >= 0 && s[p2] == '(') p2--;
    if (p1 >= p2){
        cout << 0 << ' '<< 1;
        return 0;
    }
    //cout << endl;
    //rep (i,p1,n) cout << s[i];
    //cout << endl;
    n = p2+1;
    ll len=0,ans=0,cnt = 0;
    stack <pair<int,char> > st;
    rep (i,p1,n){
        if (!st.empty() && s[i] == ')' && st.top().Y == '('){
            st.pop();
        }
        else{
            st.push(mp(i,s[i]));
        }
    }
    set <int> se;
    while (!st.empty()){
        se.insert(st.top().X);
        st.pop();
    }
    rep (i,p1,n){
        if (!st.empty() && s[i] == ')' && st.top().Y == '('){
            st.pop();
            len+=2;
        }
        else{
            st.push(mp(i,s[i]));
            if (s[i] == ')' || se.find(i) != se.end()){
                //debug(i); debug(len);
                if (len > cnt) ans = 1;
                if (len == cnt) ans++;
                cnt  = max(len,cnt);
                len = 0;
            }
        }
    }
    if (len > cnt) ans=1;
    if (len == cnt) ans++;
    cnt = max(cnt,len);
    len = n-p1-st.size();
    //debug(p1);
    cout << cnt << ' ';
  //  while (!st.empty() && st.top() == '('){ st.pop(); ans++;}
    cout << ans;

}