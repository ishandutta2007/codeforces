                            /* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int len;
//char in[300];
int st[300];
string num[300];
string in;

int main(){
    getline(cin, in);
    int p = 0;
    for(int i = 0; i < in.length(); i++){
        if(in[i] == ' ')
            continue;
        else if(in[i] == ',')
            st[p++] = 0;
        else if(in[i] == '.'){
            st[p++] = 1;
            i += 2;
        }
        else{
            num[p] = "";
            while(i < in.length() && in[i] >= '0' && in[i] <= '9')
                num[p] += in[i++];
            st[p++] = 2;
            i--;
        }
    }
    int pre = 3;
    for(int i = 0; i < p; i++){
        if(st[i] == 0){
            cout << ',';
            if(i < p - 1)
                cout << ' ';
            pre = 3;
        }
        if(st[i] == 1){
            if(pre != 3)
                cout << ' ';
            cout << "...";
            pre = 1;
        }
        if(st[i] == 2){
            if(pre == 2)
                cout << ' ';
            cout << num[i];
            pre = 2;
        }
    }
    cout << endl;
   // cin >> pre;
    return 0;
}