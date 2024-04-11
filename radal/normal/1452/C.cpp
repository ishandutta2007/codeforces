#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e9;
int main(){
    ios :: sync_with_stdio(); cout.tie();
    int T;
    cin >> T;
    while (T--){
        int n;
        string s,s1,s2;
        cin >> s;
        n = s.size();
        rep(i,0,n){
            if (s[i] == '(') s1+='(';
            if (s[i] == ')'){
                s1+=')';
            }
            if (s[i] == '[') s2+='(';
            if (s[i] == ']') s2+=')';
        }
        stack <char> st,st1;
        rep(i,0,s1.size()){
            if (!st.empty() && st.top() == '(' && s1[i] == ')') st.pop();
            else st.push(s1[i]);
        }
        rep(i,0,s2.size()){
            if (!st1.empty() && st1.top() == '(' && s2[i] == ')') st1.pop();
            else st1.push(s2[i]);
        }
        cout << (s1.size()-st.size())/2 + (s2.size()-st1.size())/2 <<endl;
    
    }
}