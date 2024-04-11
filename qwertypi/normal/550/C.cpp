#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
    char c[102];
    cin >> c;
    int len = strlen(c);
    int last[8];
    fill(last, last+8, -1);
    for(int i=len-1; i>=0; i--){
        if(last[(c[i] - '0') % 8] == -1){
            last[(c[i] - '0') % 8] = i;
        }
    }
    if(last[0] != -1){
        cout << "YES" << endl;
        cout << c[last[0]];
        return 0;
    }
    int mid[8][2];
    for(int i=0;i<8;i++){
        fill(mid[i], mid[i]+2, -1);
    }
    memset(mid, -1, 64);
    for(int i=len-1; i>=0; i--){
        for(int j=0;j<8;j++){
            int ind = (j + (c[i] - '0') * 10) % 8;
            if(last[j] != -1 && last[j] > i && mid[ind][0] == -1){
                mid[ind][0] = i;
                mid[ind][1] = last[j];
            }
        }
    }
    if(mid[0][0] != -1){
        cout << "YES" << endl;
        cout << c[mid[0][0]] << c[mid[0][1]];
        return 0;
    }
    for(int i=len-1; i>=0; i--){
        for(int j=0;j<8;j++){
            int ind = ((c[i] - '0') * 100 + (c[mid[j][0]]-'0')*10 + c[mid[j][1]]-'0') % 8;
            if(mid[j][0] > i && mid[j][0] != -1 && ind == 0){
                cout << "YES" << endl;
                cout << c[i] << c[mid[j][0]] << c[mid[j][1]];
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}