#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;

    while(q--){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        set<string> forb;

        int two, last;
        two = 1;
        last = 0;

        while(two <= n){
            two *= 2;
            last++;
        }

        last = min(last, k);

        int p[n + 1];
        for(int i = 0; i<n; i++){
             if(s[i] == '0') p[i + 1] = p[i] + 1;
             else p[i + 1] = p[i];
        }

        for(int i = 0; i<=n - k; i++){
            if(p[i + k - last] > p[i]) continue;

            string u;

            for(int j = k - last; j<k; j++){
                u.push_back('0' + '1' - s[i + j]);
            }

            forb.insert(u);
        }

        bool flag = 0;

        for(int i = 0; i<(1 << last); i++){
            string t;
            for(int j = 0; j<last; j++){
                if(1 << (last - 1 - j) & i) t.push_back('1');
                else t.push_back('0');
            }

            if(!forb.count(t)){
                cout << "YES" << endl;

                for(int j = 0; j<k - last; j++){
                    cout << '0';
                }

                cout << t << endl;
                flag = 1;
                break;
            }
        }

        if(!flag){
            cout << "NO" << endl;
        }

    }

}