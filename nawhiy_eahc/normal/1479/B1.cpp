#include <bits/stdc++.h>

using namespace std;
int a[100002];
vector<pair<int, int > > cnt;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int c = 1;
    for(int i=2;i<=n+1;i++){
        if(a[i] != a[i-1]){
            cnt.push_back({a[i-1], c >= 2?2:1 });
            c = 0;
        }
        c++;
    }
    int m = cnt.size();
    int ans = 0, exst = 0, t = 0;
    for(int i=0;i<m;i++){
        if(cnt[i].second == 1){
            ans++;
            if(cnt[i].first == exst) t = 0;
            else t++;

            if(t == 2) exst = 0;
        }
        else if(exst == cnt[i].first){
            ans++; t = 0;
        }
        else{
            ans += 2; exst = cnt[i].first; t = 0;
        }
    }

    cout << ans;
}