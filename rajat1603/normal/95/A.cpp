#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
string arr[N];
string w;
char letter;
int mark[N];
char same(char a , char b){
    if(isupper(b)){
        return toupper(a);
    }
    else{
        return tolower(a);
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    cin >> w;
    cin >> letter;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j + arr[i].size() - 1 < w.size() ; ++j){
            bool ok = 1;
            for(int k = j ; k < j + arr[i].size() ; ++k){
                if(tolower(w[k]) != tolower(arr[i][k - j])){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                for(int k = j ; k < j + arr[i].size() ; ++k){
                    mark[k] = 1;
                }
            }
        }
    }
    for(int i = 0 ; i < w.size() ; ++i){
        if(mark[i]){
            if(tolower(w[i]) == tolower(letter)){
                if(tolower(w[i]) == 'a'){
                    w[i] = same('b' , w[i]);
                }
                else{
                    w[i] = same('a' , w[i]);
                }
            }
            else{
                w[i] = same(letter , w[i]);
            }
        }
    }
    cout << w << endl;
}