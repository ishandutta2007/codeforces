#include <bits/stdc++.h>

using namespace std;

vector<int>sk[3];

int main(){
        int n;
        cin >> n;
        int k;
        for(int j = 0;j<n;j++){
                cin >> k;
                if(k==0)sk[0].push_back(0);
                else if(k>0)sk[1].push_back(k);
                else sk[2].push_back(k);
        }
        cout << 1 << " " << sk[2].back() << "\n";
        sk[2].pop_back();
        if(sk[1].size() == 0){
                cout << 2 << " ";
                cout << sk[2].back() << " ";
                sk[2].pop_back();
                cout << sk[2].back();
                sk[2].pop_back();
                cout << "\n";
        }
        else{
                cout << 1 << " ";
                cout << sk[1].back();
                cout << "\n";
                sk[1].pop_back();
        }
        cout << sk[0].size()+sk[1].size()+sk[2].size() <<  " ";
        for(int i = 0;i<3;i++)
                for(int j = 0;j<sk[i].size();j++)
                        cout << sk[i][j] << " ";
        return 0;
}