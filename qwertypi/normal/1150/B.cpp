#include <iostream>
#include <string>
#define inf (1 << 14)
using namespace std;
bool block[50][50];
int N;
bool inBoard(int x, int y){
    bool res = 0 <= x && 0 <= y && x < N && y < N && !block[x][y];
    block[x][y] = true;
    return res;
}

void fill(int x, int y){
    if(!(inBoard(x, y) && inBoard(x+2, y) && inBoard(x+1, y+1) && inBoard(x+1, y-1) && inBoard(x+1, y))){
        cout << "NO";
        exit(0);
    }

}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<N;j++){
            block[i][j] = s[j] == '#';
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!block[i][j]){
                fill(i, j);
            }
        }
    }
    cout << "YES";
    return 0;
}