//
// Created by oOrmlis on 24.11.2019.
//
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int arr[200001];
vector<pair<int, int>> arr2;
vector<pair<pair<int, int>, int>> requests;

int main() {
    int n;
    cin >> n;
    arr2.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr2[i] = {arr[i], -i};
    }
    int m; cin >> m;
    int k, pos;
    requests.resize(m);
    indexed_set ans;
    vector<int> answers(m);
    for(int i = 0; i < m; ++i) {
        cin >> k >> pos;
        requests[i] = {{k, pos}, i};
    }
    sort(requests.begin(), requests.end());
    sort(arr2.begin(), arr2.end());
    int cur = 0;
    for(auto p: requests) {
        k = p.first.first;
        pos = p.first.second;
        int i = p.second;
        while (cur != k) {
            cur++;
            ans.insert(-arr2[n - cur].second);
        }
        auto a = ans.find_by_order(pos - 1);
        answers[i] = arr[*a];
    }
    for(auto e: answers) {
        cout << e << '\n';
    }
    return 0;
}