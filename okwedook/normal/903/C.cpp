#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mymap;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        mymap[temp]++;
    }
    int ans = 1;
    for (auto i : mymap) 
        ans = max(ans, i.second);
    cout << ans;
    //system("pause");
    return 0;
}