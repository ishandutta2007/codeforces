#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    fastIO;
    int n;
    cin >> n;
    int req[n];
    for(int i = 0;i<n;i++)cin >> req[i];
    int rem = 0;
    for(int j = 0;j<n;j++){
        req[j]-=rem;
        rem=0;
        if(req[j]%2==1){
            if(j==n-1){
                cout << "NO\n";
                return 0;
            }
            else if(req[j+1]>=1){
                rem = 1;
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}