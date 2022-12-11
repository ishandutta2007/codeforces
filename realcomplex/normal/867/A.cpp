#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    char l,t;
    cin >> l;
    int cnt = 0,cnt1 = 0;
    for(int j = 1;j<n;j++){
        cin >> t;
        if(t != l){
            if(t == 'F'){
                cnt++;
            }
            else{
                cnt1++;
            }
        }
        l = t;
    }
    if(cnt > cnt1) cout << "YES";
    else cout << "NO";
    return 0;
}