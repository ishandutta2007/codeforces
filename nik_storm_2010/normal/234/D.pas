uses math;
var
  a,l,r:array[1..100] of longint; good,may:array[0..100] of boolean;
  cnt,m,k,i,x,n,q,w,e,j,ll,rr:longint; s:string;


begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  readln(m,k); m:=m-k;
  for i:=1 to k do
  begin
    if (i=k) then readln(x) else read(x);
    good[x]:=true;
  end;
  readln(n);
  for i:=1 to n do
  begin
    readln(s); readln(cnt); q:=0; w:=0; e:=0;
    for j:=1 to cnt do
    begin
      if (j=cnt) then readln(x) else read(x);
      if (good[x]) then inc(q) else if (x=0) then inc(w) else inc(e);
    end;
    if (w<=m-e) then l[i]:=q else l[i]:=q+(w-m+e);
    r[i]:=q+min(w,k-q);
    ll:=max(ll,l[i]); rr:=max(rr,r[i]);
  end;
  for i:=1 to n do may[i]:=true;
  for i:=ll to rr do
  begin
    k:=0;
    for j:=1 to n do if (l[j]<=i) and (i<=r[j]) then inc(k);
    for j:=1 to n do
    begin
      if (i<=l[j]) or ((k=1)and(l[j]<=i)and(i<=r[j])) then may[j]:=may[j] and true else may[j]:=may[j] and false;
      if (i<=r[j]) then inc(a[j]);
    end;
  end;
  for i:=1 to n do
  begin
    if (may[i]) then writeln(0) else
    if (a[i]=0) then writeln(1) else writeln(2);
  end;
  close(input); close(output);
end.