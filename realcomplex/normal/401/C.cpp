#include <bits/stdc++.h>

using namespace std;

int main(){
        int n,m;
        cin >> n >> m;
        int s = n+m;
        if(s/3 > n || s/3 > m*2 || n-m > 1){
                cout << -1 << "\n";
                exit(0);
        }
        if(n>=m){
                for(int j = 0;j<s;j++)cout << j%2;
        }
        else{
                string ans;
                for(int i = 0;i<n;i++){
                        ans += "10";
                        m--;
                }
                for(int j = 0;j<ans.size();j++){
                        cout << ans[j];
                        if(ans[j] == '1'){
                                if(m>0){
                                        cout << 1;
                                        m--;
                                }
                        }
                }
                if(m>0){
                        cout << 1;
                        m--;
                }
                if(m>0){
                        cout << 1;
                        m--;
                }
        }
        cout << endl;
        return 0;
}