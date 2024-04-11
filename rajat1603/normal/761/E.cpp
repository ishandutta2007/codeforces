#include "bits/stdc++.h"
using namespace std;
const int N = 3005;
const long long inf = 1e9 + 9;
struct data{
    pair < long long , long long > botleft;
    pair < long long , long long > topright;
    vector < pair < pair < long long , long long > , int > > v;
    data(){
        botleft = {0 , 0};
        topright = {0 , 0};
        v.clear();
    }
    pair < long long , long long > cw(pair < long long , long long > pt){
        swap(pt.first , pt.second);
        pt.second *= -1LL;   
        return pt;
    }
    void cw(){
        botleft = cw(botleft);
        topright = cw(topright);
        for(auto &it : v){
            it.first = cw(it.first);
        }
        update();
    }
    void shift(long long x , long long y){
        botleft.first += x;
        botleft.second += y;
        topright.first += x;
        topright.second += y;
        for(auto &it : v){
            it.first.first += x;
            it.first.second += y;
        }
    }
    void update(){
        for(auto it : v){
            topright.first = max(topright.first , it.first.first);
            botleft.first = min(botleft.first , it.first.first);
            botleft.second = min(botleft.second , it.first.second);
            topright.second = max(topright.second , it.first.second);
        }
    }
};
int n;
int a , b;
vector < int > v[N];
data ans;
long long ansx[N];
long long ansy[N];
data dfs(int node , int parent){
    vector < data > lol;
    lol.clear();
    for(int next : v[node]){
        if(next != parent){
            lol.push_back(dfs(next , node));
        }
    }
    data res;
    if(lol.empty()){
        res.botleft = make_pair(0LL , 0LL);
        res.topright = make_pair(0LL , 0LL);
        res.v.clear();
        res.v.push_back(make_pair(make_pair(0LL , 0LL) , node));
        res.update();
    }
    else{
        if(lol.size() == 1){
            res = lol[0];
            res.shift(0 , -1);
            if(res.topright.second >= -200){
                res.shift(0 , -res.topright.second - 300LL);
            }
            res.v.push_back(make_pair(make_pair(0LL , 0LL) , node));
            res.update();
        }
        else if(lol.size() == 2){
            lol[0].cw();
            lol[1].cw();
            lol[1].cw();
            lol[1].cw();
            if(lol[0].topright.first >= -200){
                lol[0].shift(-lol[0].topright.first - 300 , 0);
            }
            lol[0].update();
            if(lol[1].botleft.first <= max(200LL , lol[0].topright.first + 200LL)){
                lol[1].shift(-lol[1].botleft.first + max(300LL , lol[0].topright.first + 300LL) + 300LL , 0);
            }
            res.v.insert(res.v.end() , lol[0].v.begin() , lol[0].v.end());
            res.v.insert(res.v.end() , lol[1].v.begin() , lol[1].v.end());
            res.v.push_back(make_pair(make_pair(0LL , 0LL) , node));
            res.update();
        }
        else if(lol.size() == 3){
            lol[0].cw();
            /*if(node == 200){
                for(auto it : lol[200].v){
                    cout << it.first.first << " " << it.first.second << " " << it.second << endl;
                }
            }*/
            lol[2].cw();
            lol[2].cw();
            lol[2].cw();
            /*if(node == 200){
                for(auto it : lol[200].v){
                    cout << it.first.first << " " << it.first.second << " " << it.second << endl;
                }
            }*/
            if(lol[0].topright.first >= -200){
                lol[0].shift(-lol[0].topright.first - 300 , 0);
            }
            lol[0].update();
            if(lol[2].botleft.first <= max(200LL , lol[0].topright.first + 200LL)){
                lol[2].shift(-lol[2].botleft.first + max(300LL , lol[0].topright.first + 300LL) + 300LL , 0);
            }
            lol[2].update();
            if(lol[1].topright.second >= min(-200LL , min(lol[0].botleft.second - 200LL , lol[2].botleft.second - 200LL))){
                lol[1].shift(0 , -lol[1].topright.second + min(-300LL , min(lol[0].botleft.second - 300 , lol[2].botleft.second - 300)));
            }
            lol[1].update();
            for(int i = 0 ; i < 3 ; ++i){
                res.v.insert(res.v.end() , lol[i].v.begin() , lol[i].v.end());
            }
            res.v.push_back(make_pair(make_pair(0LL , 0LL) , node));
            res.update();
        }
    }
    return res;
}
int main(){
    cin >> n;
    for(int i = 1 ; i < n ; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(v[i].size() > 4){
            cout << "NO\n";
            return 0;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(v[i].size() < 4){
            ans = dfs(i , 0);
            break;
        }
    }
    for(auto it : ans.v){
        ansx[it.second] = it.first.first;
        ansy[it.second] = it.first.second;
    }
    cout << "YES\n";
    for(int i = 1 ; i <= n ; ++i){
        cout << ansx[i] << " " << ansy[i] << "\n";
    }
}