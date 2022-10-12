#include<bits/stdc++.h>

using namespace std;

// https://github.com/E869120/kyopro_educational_90/blob/main/sol/041-03.cpp

struct Point {
	long long px, py;
};

Point operator+(const Point& a1, const Point& a2) {
	return Point{ a1.px + a2.px, a1.py + a2.py };
}

Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}

bool operator<(const Point& a1, const Point& a2) {
	if (a1.px < a2.px) return true;
	if (a1.px > a2.px) return false;
	if (a1.py < a2.py) return true;
	return false;
}

//  p1  p2 
long long crs(Point p1, Point p2) {
	return p1.px * p2.py - p1.py * p2.px;
}

long long abcr(Point p1, Point p2) {
  return abs(crs(p1,p2));
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long N,S;
Point G[100009];

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) { cin >> G[i].px >> G[i].py; }
	sort(G + 1, G + N + 1);

	vector<Point> G1, G2, Th;
	G1.push_back(G[1]); G2.push_back(G[1]);
	G1.push_back(G[2]); G2.push_back(G[2]);
	for (int i = 3; i <= N; i++) {
		while (G1.size() >= 2 && crs(G1[G1.size() - 1] - G1[G1.size() - 2], G[i] - G1[G1.size() - 1]) <= 0) G1.pop_back();
		while (G2.size() >= 2 && crs(G2[G2.size() - 1] - G2[G2.size() - 2], G[i] - G2[G2.size() - 1]) >= 0) G2.pop_back();
		G1.push_back(G[i]);
		G2.push_back(G[i]);
	}
	for (int i = 0; i < G1.size(); i++) { Th.push_back(G1[i]); }
	for (int i = (int)G2.size() - 2; i >= 1; i--) { Th.push_back(G2[i]); }

  // for(auto &nx : Th){
  //   cout << nx.px << ' ' << nx.py << '\n';
  // }
  int ts=Th.size();
  long long cp=-1;
  int p1,p2,p3;
  for(int i=0;i<ts;i++){
    int j=(i+1)%ts,k=(i+2)%ts;
    while(k!=i){
      if(j==k){k++;k%=ts;continue;}
      // cout << i << ' ' << j << ' ' << k << '\n';
      if(cp<abcr(Th[j]-Th[i],Th[k]-Th[i])){
        cp=abcr(Th[j]-Th[i],Th[k]-Th[i]);
        p1=i;p2=j;p3=k;
      }
      if(abcr(Th[j]-Th[i],Th[k]-Th[i])<abcr(Th[j]-Th[i],Th[(k+1)%ts]-Th[i])){k++;k%=ts;}
      else{j++;j%=ts;}
    }
  }

  // cout << cp << '\n';
  Point r1=Th[p1]+Th[p2]-Th[p3];
  Point r2=Th[p2]+Th[p3]-Th[p1];
  Point r3=Th[p3]+Th[p1]-Th[p2];
  cout << r1.px << ' ' << r1.py << '\n';
  cout << r2.px << ' ' << r2.py << '\n';
  cout << r3.px << ' ' << r3.py << '\n';
}