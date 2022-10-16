#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 500;
const int M = 1e7 + 100;

string t[N];
vector < int > k[N];

int gen[M],x,y,eend,n;

int main(){
  ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> t[i];
        cin >> x;
        for(int j = 0;j<x;j++){
            cin >> y;
            k[i].push_back(y);y--;
            eend = max(eend, y + (int)t[i].size());
            if(gen[y] == 0){
                gen[y] = i;
            }
            else{
                if(t[gen[y]].size() < t[i].size()){
                    gen[y] = i;
                }
            }
        }
    }
    int bld = 0,j = 0,lft = 0;
    for(int i = 0;i<eend;i++){
        if(gen[i]){
            int in = gen[i];
            if((int)t[in].size() > lft){
                bld = in;
                lft = t[bld].size();
                j = 0;
            }
        }
        if(!bld){
            cout << "a";
        }
        else{
            cout << t[bld][j];
            j++;lft--;
            if(lft == 0) bld = 0;
        }
    }
    cout << endl;
}