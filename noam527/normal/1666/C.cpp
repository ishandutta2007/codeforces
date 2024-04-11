#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<long long ,long long > PI;

//int move(PI p1, PI p2, vector<pair<int,int>>& points, vector<pair<PI, PI>>& cur_res){
//    if()
//}

int main(){
    vector<pair<long long ,long long >> points(3);
    long long x,y;
    for(int i = 0;i<3;i++){
        cin>>x>>y;
        points[i]={x,y};
    }
    sort(points.begin(), points.end());
    vector<int> res;
    if(max(points[0].second, max(points[1].second, points[2].second)) != min(points[0].second, min(points[1].second, points[2].second))){
        res.push_back(points[1].first);
        res.push_back(max(points[0].second, max(points[1].second, points[2].second)));
        res.push_back(points[1].first);
        res.push_back(min(points[0].second, min(points[1].second, points[2].second)));
    }
    if(points[0].first != points[1].first){
        res.push_back(points[0].first);
        res.push_back(points[0].second);
        res.push_back(points[1].first);
        res.push_back(points[0].second);
    }
    if(points[2].first != points[1].first){
        res.push_back(points[2].first);
        res.push_back(points[2].second);
        res.push_back(points[1].first);
        res.push_back(points[2].second);
    }
    cout<<res.size() / 4<<endl;
    int i = 0;
    for(auto p : res){
        cout<<p<<" ";
        i++;
        if (i % 4 == 0){
            cout<<endl;
        }
    }
    return 0;
}