#include "bits/stdc++.h"
using namespace std;
string a[2];
string b[2];
set < string > s;
set < string > visited;
int main(){
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    s.insert(a[0] + a[1]);
    visited.insert(a[0] + a[1]);
    while(!s.empty()){
        string str = *s.begin();
        s.erase(s.begin());
        if(str == b[0] + b[1]){
            cout << "YES\n";
            return 0;
        }
        a[0] = str.substr(0 , 2);
        a[1] = str.substr(2 , 2);
        for(int i = 0 ; i < 2 ; ++i){
            for(int j = 0 ; j < 2 ; ++j){
                if(a[i][j] == 'X'){
                    if(i == 0){
                        swap(a[i][j] , a[i + 1][j]);
                        if(visited.find(a[0] + a[1]) == visited.end()){
                            s.insert(a[0] + a[1]);
                            visited.insert(a[0] + a[1]);
                        }
                        swap(a[i][j] , a[i + 1][j]);
                    }
                    else{
                        swap(a[i][j] , a[i - 1][j]);
                        if(visited.find(a[0] + a[1]) == visited.end()){
                            s.insert(a[0] + a[1]);
                            visited.insert(a[0] + a[1]);
                        }
                        swap(a[i][j] , a[i - 1][j]);
                    }
                    if(j == 0){
                        swap(a[i][j] , a[i][j + 1]);
                        if(visited.find(a[0] + a[1]) == visited.end()){
                            s.insert(a[0] + a[1]);
                            visited.insert(a[0] + a[1]);
                        }
                        swap(a[i][j] , a[i][j + 1]);
                    }
                    else{
                        swap(a[i][j] , a[i][j - 1]);
                        if(visited.find(a[0] + a[1]) == visited.end()){
                            s.insert(a[0] + a[1]);
                            visited.insert(a[0] + a[1]);
                        }
                        swap(a[i][j] , a[i][j - 1]);
                    }
                }
            }
        }
    }
    cout << "NO\n";
}