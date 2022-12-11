#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int cnt[105];

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int k;
    for(int j = 0;j<n;j++){
        cin >> k;
        ++cnt[k];
    }
    for(int i = 1;i<105;i++){
        for(int x = i+1;x<105;x++){
            if(cnt[i]+cnt[x] == n && cnt[i] == cnt[x]){
                cout << "YES\n" << i << " " << x;
                exit(0);
            }
        }
    }
    cout << "NO";
    return 0;
}