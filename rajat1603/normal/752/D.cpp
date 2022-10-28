#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
map < string , vector < int > > mp;
int n , len , x;
char str[N];
bool ispal(string str){
    int l = 0;
    int r = len - 1;
    while(l < r){
        if(str[l] != str[r]){
            return 0;
        }
        ++l;
        --r;
    }
    return 1;
}
vector < pair < pair < int , bool > , pair < int , bool > > > ans;
int val;
int main(){
    scanf("%d %d" , &n , &len);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s %d" , str , &x);
        mp[str].emplace_back(x);
    }
    for(auto &it : mp){
        sort(it.second.begin() , it.second.end());
    }
    for(auto &it1 : mp){
        string tmp = it1.first;
        reverse(tmp.begin() , tmp.end());
        bool p1 = ispal(it1.first);
        if(!p1){
            if(mp.find(tmp) != mp.end()){
                auto it2 = mp[tmp];
                bool p2 = ispal(tmp);
                while(!it1.second.empty() && !it2.empty()){
                    if(it1.second.back() + it2.back() > 0){
                        val += it1.second.back() + it2.back();
                        ans.push_back({{it1.second.back() , p1} , {it2.back() , p2}});
                        it1.second.pop_back();
                        it2.pop_back();
                    }
                    else{
                        break;
                    }
                }
                mp[tmp] = it2;
            }
        }
        else{
            while(it1.second.size() > 1){
                if(it1.second[it1.second.size() - 1] + it1.second[it1.second.size() - 2] > 0){
                    val += it1.second.back();
                    int x = it1.second.back();
                    it1.second.pop_back();
                    val += it1.second.back();
                    int y = it1.second.back();
                    it1.second.pop_back();  
                    ans.push_back({{x , 1} , {y , 1}});
                }
                else{
                    break;
                }
            }
        }
    }
    int ans2 = val;
    for(auto &it : mp){
        if(!it.second.empty()){
            if(ispal(it.first)){
                ans2 = max(ans2 , val + it.second.back());
            }
        }
    }
    for(auto it : ans){
        if(it.first.second){
            ans2 = max(ans2 , val - it.second.first);
        }
        if(it.second.second){
            ans2 = max(ans2 , val - it.first.first);
        }
    }
    printf("%d\n" , ans2);
}