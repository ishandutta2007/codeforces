#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt,"r",stdin);

int main(){
    string a;
    cin >> a;
    int ans = 0;
    int y = 0;
    for(int i = a.size()-1;i>0;i--){
        if(a[i]=='1'){
            y = i;
            while(y >= 0 and a[y] == '1'){
                a[y]='0';
                y--;
            }
            if(y < 0){
                ans++;
            }
            else{
                a[y] = '1';
            }
            ans ++ ;
        }
        if(a[i] == '0')
            ans ++ ;
    }
    cout << ans;
    return 0;
}