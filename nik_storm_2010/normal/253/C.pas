uses math;
var
  used:array[0..200,0..200000] of boolean; a:array[0..200000] of longint;
  q:array[1..3,1..15000000] of longint; r1,c1,r2,c2,n,st,fn,x,y,z:longint;


procedure inputdata;
var i:longint;
begin
  assign(input,'input.txt'); reset(input);
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(r1,c1,r2,c2);
  close(input);
end;


procedure outputdata(ans:longint);
begin
  assign(output,'output.txt'); rewrite(output);
  writeln(ans);
  close(output); halt;
end;


procedure add(x,y,z:longint);
begin
  used[x,y]:=true;
  q[1,fn]:=x; q[2,fn]:=y; q[3,fn]:=z;
  inc(fn);
end;


procedure out(var x,y,z:longint);
begin
  x:=q[1,st]; y:=q[2,st]; z:=q[3,st];
  inc(st);
end;


begin
  inputdata;
  st:=1; fn:=1; add(r1,c1,0);
  while st<>fn do
  begin
    out(x,y,z); if (x=r2) and (y=c2) then outputdata(z);
    if (y<>1) and (not used[x,y-1]) then add(x,y-1,z+1);
    if (y<>a[x]+1) and (not used[x,y+1]) then add(x,y+1,z+1);
    if (x<>1) and (not used[x-1,min(y,a[x-1]+1)]) then add(x-1,min(y,a[x-1]+1),z+1);
    if (x<>n) and (not used[x+1,min(y,a[x+1]+1)]) then add(x+1,min(y,a[x+1]+1),z+1);
  end;
end.