#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a;
        int ptr = 0;

        for(int i = 0; i<n; i++){
            int x;
            cin >> x;

            while(a.size() >= 2){
                if(x > a[a.size() - 1]){
                    a.pop_back();
                }

                else if(x > a.back()){
                    break;
                }

                else{
                    a.push_back(x);
                    break;
                }
            }

            if(a.size() == 1){
                if(a[0] > x) a.push_back(x);
            }

            if(a.size() == 0){
                a.push_back(x);
            }
        }

        if(a.size() == 1){
            cout << "YES" << endl;
        }

        else{
            cout << "NO" << endl;
        }


    }

}