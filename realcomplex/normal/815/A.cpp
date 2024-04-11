#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string its(int sk){
    string re;
    while(sk > 0){
        re = char((sk % 10) + 48) + re;
        sk /= 10;
    }
    return re;
}

int main() {

    int n,m;
    cin >> n >> m;
    int lauks[n][m];
    int lauks_[n][m];
    for(int i = 0;i<n;i++){
        for(int x = 0;x<m;x++){
            cin >> lauks[i][x];
            lauks_[i][x] = lauks[i][x];
        }
    }
    string p;
    vector<string>moveset1,moveset2;
    int min_;
    for(int i = 0;i<n;i++){
        min_ = 10000;
        for(int x = 0;x<m;x++){
            if(lauks[i][x] < min_){
                min_ = lauks[i][x];
            }
        }
        p = "row " + its(i + 1);
        for(int x = 0;x<min_;x++){
            moveset1.push_back(p);
        }
        for(int x = 0;x<m;x++){
            lauks[i][x] -= min_;
        }
    }
    for(int x = 0;x<m;x++){
        min_ = 10000;
        for(int i = 0;i<n;i++){
            if(lauks[i][x] < min_){
                min_ = lauks[i][x];
            }
        }
        p = "col " + its(x + 1);
        for(int i = 0;i<min_;i++){
            moveset1.push_back(p);
        }
        for(int i = 0;i<n;i++){
            lauks[i][x] -= min_;
        }
    }
    // -------------------------
    for(int x = 0;x<m;x++){
        min_ = 10000;
        for(int i = 0;i<n;i++){
            if(lauks_[i][x] < min_){
                min_ = lauks_[i][x];
            }
        }
        p = "col " + its(x + 1);
        for(int i = 0;i<min_;i++){
            moveset2.push_back(p);
        }
        for(int i = 0;i<n;i++){
            lauks_[i][x] -= min_;
        }
    }
    for(int i = 0;i<n;i++){
        min_ = 10000;
        for(int x = 0;x<m;x++){
            if(lauks_[i][x] < min_){
                min_ = lauks_[i][x];
            }
        }
        p = "row " + its(i + 1);
        for(int x = 0;x<min_;x++){
            moveset2.push_back(p);
        }
        for(int x = 0;x<m;x++){
            lauks_[i][x] -= min_;
        }
    }
    bool i1,i2 = true;
    i1 = true;
    i2 = true;
    for(int i = 0;i<n;i++){
        for(int x = 0;x<m;x++){
            if(lauks[i][x] != 0){
                i1 = false;
            }
            if(lauks_[i][x] != 0){
                i2 = false;
            }
        }
    }
    if(i1 == false && i2 == false){
        cout << -1;
    }
    else{
        if(i1 == true && i2 == false){
            cout << moveset1.size() << "\n";
            for(int i = 0;i<moveset1.size();i++){
                cout << moveset1[i] << "\n";
            }
        }
        else if(i1 == false && i2 == true){
            cout << moveset2.size() << "\n";
            for(int i = 0;i<moveset2.size();i++){
                cout << moveset2[i] << "\n";
            }
        }
        else{
            if(moveset1.size() < moveset2.size()){
                cout << moveset1.size() << "\n";
                for(int i = 0;i<moveset1.size();i++){
                    cout << moveset1[i] << "\n";
                }
            }
            else{
                cout << moveset2.size() << "\n";
                for(int i = 0;i<moveset2.size();i++){
                    cout << moveset2[i] << "\n";
                }
            }
        }
    }
	return 0;
}