#include <bits/stdc++.h>
using namespace std;

int solve(int mask, vector<int> pos){
    int x = __builtin_popcount(mask);
    random_shuffle(pos.begin(), pos.end());

    if(x < 3){
        int res[pos.size()][pos.size()];

        for(int i = 0; i<pos.size(); i++){
            for(int j = i + 1; j<pos.size(); j++){
                cout << "? " << pos[i] << " " << pos[j] << endl;
                fflush(stdout);

                int a;
                cin >> a;

                res[i][j] = a;
                res[j][i] = a;
                res[i][i] = 0;
                res[j][j] = 0;
            }
        }

        int ps = -1;
        int mi = 1e9 + 7;
        for(int i = 0; i<pos.size(); i++){
            int sum = 0;
            for(int j = 0; j<pos.size(); j++){
                sum += res[i][j];
            }

            if(sum < mi){
                ps = i;
                mi = sum;
            }
        }

        return pos[ps];
    }

    int target = x / 2 + 1;
    int good;
    int ptr = 0;

    while(1){
        int cur = mask;
        for(int i = 0; i<x - 1; i++){
            int cancer = rand() % pos.size();
            while(cancer == ptr) cancer = rand() % pos.size();

            cout << "? " << pos[ptr] << " " << pos[cancer] << endl;
            fflush(stdout);

            int a;
            cin >> a;

            cur &= a;
            
            if(__builtin_popcount(cur) > 8){
                break;
            }

            if(__builtin_popcount(cur) <= target && __builtin_popcount(cur) >= 2){
                int mi = cur;
                int ans[pos.size()];
                ans[ptr] = 1e9 + 7;

                for(int j = 0; j<pos.size(); j++){
                    if(j != ptr){
                        cout << "? " << pos[ptr] << " " << pos[j] << endl;
                        fflush(stdout);

                        cin >> ans[j];
                        mi &= ans[j];

                        if(__builtin_popcount(mi) == 0) return pos[ptr];
                        else if(__builtin_popcount(mi) == 1) break;
                    }
                }

                if(__builtin_popcount(mi) == 1) break;

                int new_mask = mi;
                vector<int> new_pos;

                for(int j = 0; j<pos.size(); j++){
                    if(ans[j] == mi || ans[j] == 1e9 + 7) new_pos.push_back(pos[j]);
                }

                return solve(new_mask, new_pos);
            }

            else if(__builtin_popcount(cur) == 0) return pos[ptr];

            else break;
        }

        ptr++;
    }

}

int main(){
    srand(time(NULL));
    int n;
    cin >> n;

    int x = 1;
    while(x < n) x *= 2;

    vector<int> v;
    for(int i = 0; i<n; i++){
        v.push_back(i + 1);
    }

    int zero = solve(x -1, v);
    int ans[n];

    for(int i = 0; i<n; i++){
        if(i + 1 != zero){
            cout << "? " << zero << " " << i + 1 << endl;
            fflush(stdout);

            int a;
            cin >> a;
            ans[i] = a;
        }

        else ans[i] = 0;
    }

    cout << "! ";
    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }

}