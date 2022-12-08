                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m, k, t;
vector <int> v[40010];
int cnt[40010], sum[40010];
string str[3] = {"Carrots", "Kiwis", "Grapes"};
int main(){
    int a, b;
    cin >> n >> m >> k >> t;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        a--, b--;
        cnt[a]++;
        v[a].push_back(b);
    }
    for(int i = 0; i < n; i++)
        sort(v[i].begin(), v[i].end());
    sum[0] = cnt[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + cnt[i];
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        a--, b--;
        int bad = 0;
        if(a > 0)
            bad += sum[a - 1];
        bool fl = false;
        for(int i = 0; i < v[a].size(); i++){
            if(v[a][i] < b)
                bad++;
            if(v[a][i] == b)
                fl = true;
        }
        int ted = a * m + b - bad;
        if(fl)
            cout << "Waste" << endl;
        else cout << str[ted % 3] << endl;
    }
    return 0;
}