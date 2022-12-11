#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    string s;
    int p;
    deque<int>sk;
    int times = 0;
    int t = 1;
    for(int i = 0;i<n*2;i++){
        cin >> s;
        if(s == "add"){
            cin >> p;
            sk.push_back(p);
        }
        else{
            if(sk.size() > 0){
                if(sk.back() != t){
                    times++;
                    sk.clear();
                }
                else{
                    sk.pop_back();
                }

            }
            t++;
        }
    }
    cout << times;
	return 0;
}