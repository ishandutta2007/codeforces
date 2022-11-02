#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string o, h;
    cin >> n >> o >> h;
    vector<int> a, b, c, d;
    for (int i = 0; i < n; i++){
        if (o[i] == '0' && h[i] == '0') a.push_back(i + 1);
		if (o[i] == '1' && h[i] == '0') b.push_back(i + 1);
		if (o[i] == '0' && h[i] == '1') c.push_back(i + 1);
		if (o[i] == '1' && h[i] == '1') d.push_back(i + 1);
    }
    for (int i = 0; i <= b.size(); i++){
        for (int j = 0; j <= d.size(); j++){
            int s = c.size() - i - 2 * j + d.size();
            if (s >= 0 && s <= c.size()){
                int m = s + i + j;
                if ( m <= n / 2 && a.size() >= n / 2 - m){
                    for (int f = 0; f < i; f++) cout << b[f] << " ";
                    for (int f = 0; f < s; f++) cout << c[f] << " ";
                    for (int f = 0; f < j; f++) cout << d[f] << " ";
                    for (int f = 0; f < n / 2 - m; f++) cout << a[f] << " ";
                    return 0;
                }
            }
        }
    }
    cout << -1;
}