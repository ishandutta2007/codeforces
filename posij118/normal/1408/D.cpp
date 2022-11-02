#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int a[n], b[n];
    pair<int, int> c[m];

    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i<m; i++){
        cin >> c[i].first >> c[i].second;
    }

    sort(c, c + m);

    vector<pair<int, int> > pts;
    //pts.push_back({c[m - 1].first + 1, 0});
    int ma = -1;

    for(int i = m - 1; i>=0; i--){
        if(c[i].second > ma){
            pts.push_back({c[i].first + 1, ma + 1});
            ma = c[i].second;
        }
    }

    pts.push_back({0, ma + 1});
    reverse(pts.begin(), pts.end());

    long long ans = 0;
    int mi = 1e9;

    int d = -1;
    int h = 1e6 + 1;
    int cnt = 0;

    while(h > d + 1){
        vector<pair<int, int> > sts;
        cnt++;

        int mid = (d + h) / 2;
        bool flag = 0;
        bool flag2 = 0;

        for(int i = 0; i<n; i++){
            vector<pair<int, int> > st;
            int rr = -1;

            for(int j = 0; j<pts.size(); j++){
                int l = max(0, pts[j].first - a[i]);
                int r = mid - max(0, pts[j].second - b[i]);

                if(l <= r){
                    if(l > rr){
                        if(rr != -1){
                            sts.push_back({rr + 1, -1});
                        }
                        sts.push_back({l, 1});

                    }
                    rr = r;
                }
            }

            if(rr != -1) sts.push_back({rr + 1, -1});

            else{
                flag2 = 1;
                break;
            }
        }

        if(flag2){
            d = mid;
            continue;
        }

        int cur = 0;
        int new_cur = 0;
        sort(sts.begin(), sts.end());
        for(int j = 0; j<sts.size(); j++){
            if(j == 0){
                new_cur = cur + sts[j].second;
            }

            else if(sts[j].first == sts[j - 1].first){
                new_cur += sts[j].second;
            }

            else{
                cur = new_cur;
                if(cur == n){
                    flag = 1;
                    break;
                }
                new_cur += sts[j].second;
            }

        }

        if(flag){
            h = mid;
        }

        else{
            d = mid;

        }


        for(auto x: sts){
                //cout << x.first << " " << x.second << endl;
        }
        //cout << endl;
    }

    for(auto x: pts){
                //cout << x.first << " " << x.second << endl;
    }
    //cout << endl;

    cout << h;

}