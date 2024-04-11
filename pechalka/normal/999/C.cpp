#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<set<int>>A (26, {n});
    for(int i = 0; i < n; ++i)
        A[s[i] - 'a'].insert(i);
    int i = 0;
    while (k > 0){
        if (A[i].size() > 1){
            A[i].erase(A[i].begin());
            k--;
        }
        else
            i++;
    }
    string s2 = "";
    for (int i = 0; i < n; ++i)
        if (A[s[i] - 'a'].find(i) != A[s[i] - 'a'].end())
            s2 += s[i];
    cout << s2;
    return 0;
}