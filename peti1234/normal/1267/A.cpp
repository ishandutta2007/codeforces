#include <bits/stdc++.h>

using namespace std;
long long n;
long long sok=1000000000000000001;
long long db, ido, optveg;
vector<pair<long long, pair<long long, long long> > > sz;
priority_queue<pair<long long, long long > > q;
int main()
{
    ios_base::sync_with_stdio(false);
    optveg=sok;
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        sz.push_back({a, {c, b}});
    }
    sz.push_back({sok, {1, sok}});
    sort(sz.begin(), sz.end());
    for (long long i=0; i<sz.size(); i++) {
        long long kezd=sz[i].first;
        long long seb=sz[i].second.first;
        long long veg=sz[i].second.second;
        if (optveg<=kezd) {
            //cout << "plusz" << " " << ido << " " << optveg << "\n";
            db++;
            ido=optveg;
            optveg=ido-q.top().first;
            while(q.size()>0 && ido-q.top().first<=kezd) {
                while(q.size()>0 && ido-q.top().first>q.top().second) {
                    //cout << "torol" << " " << q.top().first << " " << q.top().second << " " << ido << endl;
                    q.pop();
                    if (q.size()>0) {
                        optveg=ido-q.top().first;
                    }
                }
                if (q.size()>0) {
                    long long mini=min(kezd, q.top().second);
                    long long ans=(-mini+ido)/q.top().first;
                    //cout << "nagylepes" << kezd << " " << q.top().second << " " << q.top().first << " " << ans << endl;
                    db+=ans;
                    ido-=ans*q.top().first;
                    optveg=ido-q.top().first;
                }
            }
        }
        while(q.size()>0 && ido-q.top().first>q.top().second) {
            //cout << "torol" << " " << q.top().first << " " << q.top().second << " " << ido << endl;
            q.pop();
            if (q.size()>0) {
                optveg=ido-q.top().first;
            }
        }
        if (q.size()>0) {
            if (kezd+seb<optveg) {
                ido=kezd;
            }
            optveg=min(optveg, kezd+seb);
        } else {
            ido=kezd;
            optveg=kezd+seb;
        }
        q.push({-seb, veg});
        //cout << "vege" << " " << db << " " << ido << " " << optveg << "\n";
    }
    cout << db << "\n";
    return 0;
}
//az optveg pontatlan az 52. sorban