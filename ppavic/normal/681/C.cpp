#include <cstdio>
#include <queue>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int n,x;
string cur;
string next;
priority_queue<int,vector<int> ,greater<int> > heap;
vector <string> sol;
int c = 0;

string toString(int a){
    bool les = false;
    string s = "";
    if(a < 0){
		les = true;
		a = abs(a);
    }
    if(a == 0) s = "0";
    while(a!=0){
        string num(1,a%10+'0');
        s = num+s;
        a=a/10;
    }
    if(les){
		s = "-" + s;
    }
    return s;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
             cin >> cur;
        if(cur == "insert"){
            cin >> x;
            heap.push(x);
            c++;
            sol.push_back(cur + " "+toString(x)+"\n");
        }
        if(cur == "removeMin"){
            if(heap.size() == 0){
				c++;
                sol.push_back("insert 0\n");
				heap.push(0);
            }
            heap.pop();
            c++;
            sol.push_back(cur+"\n");
        }
        if(cur == "getMin"){
            cin >> x;
            if(heap.size() == 0){
                    c++;
                    sol.push_back("insert "+toString(x)+"\n");
                    heap.push(x);
                    c++;
            sol.push_back("getMin "+toString(x)+"\n");
                    continue;
                }
            while(heap.top()!=x){
                if(heap.top() > x || heap.size()==0){
                    c++;
                    sol.push_back("insert "+toString(x)+"\n");
                    heap.push(x);
                    break;
                }
                if(heap.top()==x){
                    break;
                }
                if(heap.top() < x){
                    c++;
                    sol.push_back("removeMin\n");
                    heap.pop();
                }
                if(heap.size() == 0){
                    c++;
                    sol.push_back("insert "+toString(x)+"\n");
                    heap.push(x);
                    break;
                }
            }
            c++;
            sol.push_back("getMin "+toString(x)+"\n");
        }

    }
    printf("%d\n",c);
    for(int i = 0;i<sol.size();i++){
        cout << sol[i];
    }

}