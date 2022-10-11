from sys import stdin,stdout
# Testing https://codeforces.com/contest/659/submission/54795830

n,m=stdin.readline().strip().split(' ')
n,m=int(n),int(m)
adj_li=[[] for i in range(n+1)]
for i in range(m):
	u,v=stdin.readline().strip().split(' ');u,v=int(u),int(v)
	adj_li[u].append(v);adj_li[v].append(u)

visited=[False for i in range(n+1)]
ans=0;
for i in range(1,n+1):
	if not visited[i]:
		flag=True
		q=[(i,-1)];visited[i]=True
		while q:
			curr,par = q.pop(len(q)//2)
			for i in adj_li[curr]:
				if i!=par:
					if not visited[i]:
						q.append((i,curr));
						visited[i]=True;
						#adj[i].remove(curr)
					else:
						#print("flag false",curr,i)
						flag=False
		if flag:
			ans+=1
stdout.write(str(ans))