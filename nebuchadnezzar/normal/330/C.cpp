#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, mas_stl[100];
bool mas[100][100];
string s;
vector <pair <int, int> > ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s;
        //bool truly = false;
        for(int j = 0; j < n; ++j){
            if(s[j] == '.'){
                
                mas[i][j] = false;
            }
            else{
                mas[i][j] = true;
            }
        }
        
    }
    bool gtr = true;
    for(int i = 0; i < n; ++i){
        //cin >> s;
        bool truly = false;
        for(int j = 0; j < n; ++j){
            if(not mas[i][j]){
                if(not truly){
                    ans.push_back(make_pair(i + 1, j + 1));
                }
                truly = true;
                
            }
            
            
        }
        if(not truly){
            gtr = false;
            break;
        }
        
    }
    if(gtr){
        for(int i = 0; i < n; ++i){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        return 0;
    }
    ans.clear();
    gtr = true;
    for(int i = 0; i < n; ++i){
        //cin >> s;
        bool truly = false;
        for(int j = 0; j < n; ++j){
            if(not mas[j][i]){
                if(not truly){
                    ans.push_back(make_pair(j + 1, i + 1));
                }
                truly = true;
                
            }
            
            
        }
        if(not truly){
            gtr = false;
            break;
        }
        
    }
    if(gtr){
        for(int i = 0; i < n; ++i){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        return 0;
    }
    cout << "-1";

    return 0;
}