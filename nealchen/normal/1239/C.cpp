#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;

const int N=1e5;
enum TypeID {Hungry, Back};
struct Event {
	int who;
	TypeID type;
	long long tick;
};
template<class Type> struct Heap {
	Type beg[N*2], *end;
	bool (*cmp)(const Type &, const Type &);
	Heap(): end(beg) {}
	bool empty() const {return beg==end;}
	Type top() const {return *beg;}
	void pop() {std::pop_heap(beg, end--, cmp);}
	void push(Type x) {
		*end++=x;
		std::push_heap(beg, end, cmp);
	}
};
long long ans[N];
Heap<int> queue;
Heap<Event> event;
enum {Waiting, InQueue, OK} stage[N];
int main() {
	int n=rd(), p=rd();
	long long clk=0;
	event.cmp=[](const Event &a, const Event &b) {return a.tick>b.tick;};
	queue.cmp=[](const int &x, const int &y) {return x>y;};
	for(int i=0; i<n; ++i) event.push({i, Hungry, rd()});
	while(!event.empty()) {
		Event ev=event.top();
		event.pop();
		switch(ev.type) {
			case Hungry:
				queue.push(ev.who);
				break;
			case Back:
				stage[ev.who]=OK;
				break;
		}
		if(event.empty() || event.top().tick>ev.tick) {
			while(!queue.empty()) {
				int id=queue.top();
				if(stage[id]==Waiting) {
					stage[id]=InQueue;
					cmax(clk, ev.tick);
					event.push({id, Back, ans[id] = clk+=p});
				}
				if(stage[id]==InQueue) break;
				if(stage[id]==OK) queue.pop();
			}
		}
	}
	for(int i=0; i<n; ++i) printf("%lld%c", ans[i], " \n"[i==n-1]);
	return 0;
}