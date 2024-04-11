#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    pair<pair<int, int>, pair<int, int> > a[n];
    for(int i = 0; i<n; i++){
        int x, y, z;
        cin >> x >> y >> z;

        a[i] = {{x, y}, {z, i + 1}};
    }

    sort(a, a + n, [](pair<pair<int, int>, pair<int, int> > x, pair<pair<int, int>, pair<int, int> > y){return x.first.first < y.first.first;});


    int ptr = 0;
    int ptr2 = 0;

    int pos;
    int used[n];
    fill(used, used + n, 0);
    vector<int> cur;

    for(int i = 0; i<n; i++){
        //cout << ptr << " XXX" << ptr2 << endl;
        if(ptr < n){
            long long mi = 4e9 + 7;
            bool flag = 0;
            for(int j = ptr + 1; j<n; j++){
                if(!used[j] && !flag){
                    ptr2 = j;
                    flag = 1;
                }

                if(flag){
                    if(a[j].first.first == a[ptr2].first.first){
                        if(!used[j] && abs(a[j].first.second - a[ptr].first.second) + abs(a[j].second.first - a[ptr].second.first) < mi){
                            mi = abs(a[j].first.second - a[ptr].first.second) + abs(a[j].second.first - a[ptr].second.first);
                            pos = j;
                        }
                    }
                    
                    else break;
                }
            }

            used[pos] = 1;
            used[ptr] = 1;
            cout << a[ptr].second.second << " " << a[pos].second.second << endl;
            while(used[ptr]) ptr++;
        }
        /*
        cur.clear();
        for(int j = ptr2; j<n; j++){
            if(a[j].first.first == a[ptr2].first.first){
                if(!used[j]) cur.push_back(j);
                ptr2 = j;
            }
            else break;
        }

        i = ptr2;
        ptr2++;
        ptr = ptr2;

        sort(cur.begin(), cur.end(), [&a](int b, int c)
             {return a[b] < a[c];});

        if(cur.size() % 2){
            ptr = cur.back();
            cur.pop_back();
        }

        for(int j = 0; j<cur.size() / 2; j++){
            cout << a[cur[2*j]].second.second << " " << a[cur[2*j + 1]].second.second << endl;
        }
        */
    }
}