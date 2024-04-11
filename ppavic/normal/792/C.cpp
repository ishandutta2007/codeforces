#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5+500;


string s;
int a[N],n,sum = 0,bio[N];
vector <int> sol[2];

int main(){
    cin >> s;
    n = s.size();
    for(int i = 0;i<n;i++){
        a[i] = s[i] - '0';sum += a[i];
    }
    if(sum % 3 == 0){
        cout << s;
        return 0;
    }
    if(n == 1){
        printf("-1\n");
        return 0;
    }
    for(int i = n-1;i>=0;i--){
        if(a[i] % 3 == sum%3){
            sol[0].push_back(i);
            if(i == 0){
                i++;
                while(a[i] == 0){
                    sol[0].push_back(i);
                    i++;
                    if(i == n){
                        sol[0].erase(sol[0].end()-1);
                        break;
                    }
                }
            }
            break;
        }
    }

    for(int i = n-1;i>=0;i--){
        if(a[i] % 3 == (sum%3 * 2) % 3){
            sol[1].push_back(i);
            if(i == 0 && sol[1].size() != 2){
                sol[1].clear();
                break;
            }
            if(i == 0){
                i++;
                if(sol[1][0] == i){
                    i++;
                }
                while(a[i] == 0){
                    sol[1].push_back(i);
                    i++;
                    if(sol[1][0] == i){
                        i++;
                    }
                    if(i == n){
                        sol[1].erase(sol[1].end()-1);
                        break;
                    }
                }
            }
            if(sol[1].size() >= 2){
                break;
            }
        }
    }
    if(sol[0].size() != 0 && sol[0].size() < (sol[1].size()?sol[1].size():N)){
        for(int i = 0;i<sol[0].size();i++)
            bio[sol[0][i]] = 1;
    }
    else if(sol[1].size() != 0 && (sol[0].size()?sol[0].size():N) > sol[1].size()){
        for(int i = 0;i<sol[1].size();i++)
            bio[sol[1][i]] = 1;
    }
    else if(sol[0].size() == 0 && (sol[1].size() >= n || sol[1].size() == 0)){
        printf("-1\n");
        return 0;
    }
    else{
        for(int i = 0;i<sol[0].size();i++)
            bio[sol[0][i]] = 1;
    }
    for(int i = 0;i<n;i++){
        if(!bio[i]) cout << a[i];
    }
    cout << endl;
}