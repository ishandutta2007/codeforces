#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a[1000];
vector <int> quest;

int main() {
    int n, sum = 0, first = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) cin >> a[j], sum += a[j];
        for (int j = 0; j < l / 2; j++) first += a[j];
        if (l % 2 == 1) quest.push_back(a[l / 2]);
    }
    sort(quest.begin(), quest.end());
    int i = quest.size() - 1;
    for (int i = quest.size() - 1; i >= 0; i -= 2) first += quest[i];
    cout << first << " " << sum - first << endl;
    return 0;
}