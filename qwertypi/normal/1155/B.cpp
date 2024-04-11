#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char s[100000];
    cin >> s;
    int me_count = (n-10)/2, him_count = (n-11)/2;
    for(int i=0;i<n;i++){
        if(s[i] == '8'){
            if(him_count){
                him_count--;
            }else{
                cout << "YES";
                return 0;
            }
        }else{
            if(me_count){
                me_count--;
            }else{
                cout << "NO";
                return 0;
            }
        }
    }
}