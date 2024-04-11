#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e3+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int a[2],b[2],c[2];
void solve(){
    int n;
    cin >> n;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    rep(i,0,2*n){
        if(s1[i] =='1') a[1]++;
        else a[0]++;
        if (s2[i] == '1') b[1]++;
        else b[0]++;
        if (s3[i] == '1') c[1]++;
        else c[0]++;
    }
    int cnt=0;
    cnt += (a[1] >= a[0])+(b[1] >= b[0])+(c[1] >= c[0]);
    if (cnt <= 1){
        if (a[1] > a[0]) swap(s1,s3);
        else if (b[1] > b[0]) swap(s2,s3);
        int p1=0,p2=0;
        string t="";
        while (true){
            if (p1 == 2*n){
                while (p2 < 2*n){
                    t += s2[p2];
                    p2++;
                }
                break;
            }
            if (p2 == 2*n){
                while (p1 < 2*n){
                    t += s1[p1];
                    p1++;
                }
                break;
            }
            if (s1[p1] == s2[p2]){
                t += s1[p1];
                p1++;
                p2++;
                continue;
            }
            t += '1';
            if (s1[p1] == '1') p1++;
            else p2++;
        }
        cout << t << endl; 
        return;
    }
    if (a[0] > a[1]) swap(s3,s1);
    else if (b[0] > b[1]) swap(s2,s3);
    int p1 = 0,p2 = 0;
    string t ="";
    while (true){
        if (p1 == 2*n){
            while (p2 < 2*n){
                t += s2[p2];
                p2++;
            }
            break;
        }
        if (p2 == 2*n){
            while (p1 < 2*n){
                t += s1[p1];
                p1++;
            }
            break;
        }
        if (s1[p1] == s2[p2]){
            t += s1[p1];
            p1++;
            p2++;
            continue;
        }
        t += '0';
        if (s1[p1] == '0') p1++;
        else p2++;
    }
    cout << t << endl;
    return;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        a[0] = 0;
        a[1] = 0;
        b[0] = 0;
        b[1] = 0;
        c[1] = 0;
        c[0] = 0;
        solve();
    }
}