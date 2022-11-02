#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int solve(vector<int> ind){
    if(ind.size() <= 2) return ind.size();

    vector<int> fst, sec;

    for(int j = 30; j>=0; j--){
        int cnt = 0;
        for(int k: ind){
            if(a[k] & (1 << j)) cnt++;
        }

        if(cnt != 0 && cnt < ind.size()){
            for(int k: ind){
                if(a[k] & (1 << j)) fst.push_back(k);
                else sec.push_back(k);
            }

            return max(solve(fst), solve(sec)) + 1;
            break;
        }

    }

}


int main(){
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<int> ind;
    for(int i = 0; i<n; i++){
        ind.push_back(i);
    }

    cout << n - solve(ind);
}