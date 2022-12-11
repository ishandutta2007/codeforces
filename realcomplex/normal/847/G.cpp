#include <bits/stdc++.h>

using namespace std;

void read(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int cnt[7];

int main()
{
    //read();
    int n;
    cin >> n;
    string c;
    for(int j = 0;j<n;j++){
        cin >> c;
        for(int i = 0;i<7;i++){
            cnt[i]+=c[i]-48;
        }
    }
    int ans = 0;
    for(int i = 0;i<7;i++){
        ans = max(ans,cnt[i]);
    }
    cout << ans;
    return 0;
}