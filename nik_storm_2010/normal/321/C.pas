const mm=100010; type ee=record t,n,w:longint; end;
var
  e1,e2:array[0..2*mm] of ee; used,met,s1,s2:array[0..mm] of longint; ans:array[0..mm] of char;
  q:array[1..3,1..2500000] of longint; st,fn,it,a,b,c,r,n,i,k:longint;


procedure add(a,b,c:longint);
begin
  inc(k);
  if met[a]<>it then begin s2[a]:=0; met[a]:=it; end;
  e2[k].t:=b; e2[k].n:=s2[a]; e2[k].w:=c; s2[a]:=k;
end;


procedure build(nom,all:longint;var sum:longint);
var res,cur,i:longint;
begin
  i:=s1[nom]; used[nom]:=it; res:=0;
  while i<>0 do
  begin
    if (used[e1[i].t]<>it) and (ans[e1[i].t]=chr(0)) then
    begin
      build(e1[i].t,all,cur); res:=res+cur;
      add(e1[i].t,nom,all-cur); add(nom,e1[i].t,cur);
    end;
    i:=e1[i].n;
  end;
  sum:=res+1;
end;


procedure solve(nom,cnt,c:longint);
var max,nn,i:longint;
begin
  if cnt=1 then begin ans[nom]:=chr(c); exit; end;
  i:=s2[nom]; max:=0;
  while i<>0 do
  begin
    if e2[i].w>max then begin max:=e2[i].w; nn:=e2[i].t; end;
    i:=e2[i].n;
  end;
  if max>cnt div 2 then solve(nn,cnt,c) else
  begin
    ans[nom]:=chr(c); i:=s2[nom];
    while i<>0 do
    begin
      q[1,fn]:=e2[i].t; q[2,fn]:=e2[i].w; q[3,fn]:=c+1; inc(fn);
      i:=e2[i].n;
    end;
  end;
end;


begin

  readln(n);
  for i:=1 to n-1 do
  begin
    readln(a,b);
    c:=i*2-0; e1[c].t:=b; e1[c].n:=s1[a]; s1[a]:=c;
    c:=i*2-1; e1[c].t:=a; e1[c].n:=s1[b]; s1[b]:=c;
  end;
  st:=1; fn:=1; q[1,fn]:=1; q[2,fn]:=n; q[3,fn]:=65; inc(fn);
  while st<>fn do
  begin
    inc(it); k:=0; a:=q[1,st]; b:=q[2,st]; c:=q[3,st]; inc(st);
    build(a,b,r); solve(a,b,c);
  end;
  for i:=1 to n do write(ans[i],' ');

end.