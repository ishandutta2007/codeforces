#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

long long po(long long a, int x){
    if(x == 0) return 1;
    long long pw = po(a, x / 2);

    if(x % 2 == 0) return (pw*pw) % M;
    else return (((pw*pw) % M) * a) % M;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        long long n, p;
        cin >> n >> p;

        long long diff = 0;
        int ptr = 0;
        long long lsum, rsum;
        int last = -1;
        lsum = 0;
        rsum = 0;

        int a[n];
        set<int> s;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            s.insert(-a[i]);
        }

        vector<int> l, r;

        sort(a,a + n);
        reverse(a, a + n);


        for(auto it: s){
            bool flag = 0;
            int i = -it;
            if(ptr == n) break;

            int cnt = 0;

            if(last != -1 && p > 1 && diff != 0){
                int ex = (last - i);
                if(ex > 22){
                    for(int j = ptr; j<n; j++){
                        if(diff > 0) r.push_back(a[j]);
                        else l.push_back(a[j]);
                    }

                    flag = 1;
                }

                else{
                    for(int j = 0; j<ex; j++){
                        diff *= p;
                        if(abs(diff) > 1e6){
                            for(int j = ptr; j<n; j++){
                                if(diff > 0) r.push_back(a[j]);
                                else l.push_back(a[j]);
                            }

                            flag = 1;
                            break;
                        }
                    }
                }
            }

            if(flag) break;

            while(a[ptr] == i){
                cnt++;
                ptr++;
            }

            for(int j = 0; j<cnt; j++){
                if(diff > 0){
                    r.push_back(i);
                    diff--;
                }

                else{
                    l.push_back(i);
                    diff++;
                }
            }

            last = i;
        }

        for(auto x: l){
            lsum += po(p, x);
        }

        for(auto x: r){
            rsum += po(p, x);
        }

        if(diff > 0) cout << ((((lsum - rsum) % M) + M) % M) << endl;
        else cout << ((((rsum - lsum) % M) + M) % M) << endl;

        //cout << diff << endl;
    }

}