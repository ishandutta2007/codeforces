#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int n;

vector<string> ret;

template<typename... Args>
void print_delay(const char* a,Args... b){
    char buf[50];
    sprintf(buf, a, b...);
    ret.emplace_back(buf);
}

void job_put(int x){
    print_delay("insert %d",x);
    pq.push(x);
}

void job_remove(){
    print_delay("removeMin", 0);
    pq.pop();
}

void job_query(){
    print_delay("getMin %d",pq.top());
}

int main()
{
    scanf("%d",&n);
for(;n--;){
    char command[10]; int value;
    scanf("%s%d",command, &value);
    if(command[0] == 'i'){
        job_put(value);
    } else if(command[0] == 'g'){
        for(;;){
            if(pq.empty()){
                job_put(value);
                break;
            } else {
                int top=pq.top();
                if(top < value){
                    job_remove();
                } else if(top > value){
                    job_put(value);
                } else if(top == value) break;
            }
        }
        job_query();
    } else {
        if(pq.empty()){
            job_put(1);
        }
        job_remove();
    }
}
    printf("%d\n",ret.size());
    for(auto& a:ret) printf("%s\n",a.c_str());
    return 0;
}