#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair

using namespace std;

int n, num;
vector <int> mas[100000];
vector <pair <int, int> > ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        mas[num - 1].puba(i);
    }

    //int ans = 0;
    for (int i = 0; i < 100000; ++i) {
        //cout << i;
        if (mas[i].size() > 0) {
            if (mas[i].size() == 1) {
                ans.push_back(make_pair(i + 1, 0));
                continue;
            }
            //int prev = mas[i][0];
            int d = mas[i][1] - mas[i][0];
            bool truly = true;
            for (int j = 0; j < (int) mas[i].size() - 1; ++j) {
                if (mas[i][j + 1] - mas[i][j] != d) {
                    truly = false;
                    break;
                }
            }
            if (truly) {
                ans.puba(mapa(i + 1, d));   
            } 
        }
    }

    cout << ans.size() << endl;

    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}