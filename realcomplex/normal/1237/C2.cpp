#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;

struct pos{
    int xx;
    int yy;
    int zz;
    int id;
    bool operator< (const pos& nex) const {
        if(xx == nex.xx){
            if(yy == nex.yy){
                return zz < nex.zz;
            }
            else{
                return yy < nex.yy;
            }
        }
        else{
            return xx < nex.xx;
        }
    }
};

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<pos> pp(n);
    for(int i = 0 ; i < n; i ++) {
        cin >> pp[i].xx >> pp[i].yy >> pp[i].zz;
        pp[i].id = i + 1;
    }
    sort(pp.begin(), pp.end());
    vector<pos> nex;
    for(int i = 0 ; i < pp.size(); i ++ ){
        if(i + 1 < pp.size() && pp[i].xx == pp[i + 1].xx && pp[i].yy == pp[i + 1].yy){
            cout << pp[i].id << " " << pp[i + 1].id << "\n";
            i ++ ;
        }
        else{
            nex.push_back(pp[i]);
        }
    }
    pp = nex;
    nex.clear();
    for(int i = 0 ; i < pp.size(); i ++ ){
        if(i + 1 < pp.size() && pp[i].xx == pp[i + 1].xx){
            cout << pp[i].id << " " << pp[i + 1].id << "\n";
            i ++ ;
        }
        else{
            nex.push_back(pp[i]);
        }
    }
    pp = nex;
    nex.clear();
    for(int i = 0 ; i < pp.size(); i ++ ){
        if(i + 1 < pp.size()){
            cout << pp[i].id << " " << pp[i + 1].id << "\n";
            i ++ ;
        }
    }
    return 0;
}