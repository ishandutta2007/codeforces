#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    int m;
    int sk;
    vector<int>num;
    cin >> m;
    for(int i = 0;i<m;i++){
        cin >> sk;
        num.push_back(sk);
    }
    cin >> m;
    for(int i = 0;i<m;i++){
        cin >> sk;
        num.push_back(sk);
    }
    sort(num.begin(),num.end());
    bool can = true;
    for(int i = 1;i<num.size();i++){
        if(abs(num[i] - num[i - 1]) > 1){
            can = false;
            break;
        }
    }
    if(num.size() == 0){
        can = false;
    }
    if(num.size() >= 1){
        if(num[num.size() - 1] != n || num[0] != 1){
            can = false;
        }
    }
    if(can == true){
        cout << "I become the guy.";
    }
    else{
        cout << "Oh, my keyboard!";
    }
	return 0;
}