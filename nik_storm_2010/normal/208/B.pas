var
  used:array[1..52,1..52,1..52,1..52] of boolean; q:array[1..4,1..1000000] of longint;
  a,b:array[1..52] of char; st,fn,n,i,x,y,z,w:longint; space:char;


procedure ans(s:string);
begin
  writeln(s);
  halt;
end;


procedure add(x,y,z,w:longint);
begin
  used[x,y,z,w]:=true;
  q[1,fn]:=x; q[2,fn]:=y; q[3,fn]:=z; q[4,fn]:=w;
  inc(fn);
end;


procedure out(var x,y,z,w:longint);
begin
  x:=q[1,st]; y:=q[2,st]; z:=q[3,st]; w:=q[4,st];
  inc(st);
end;


begin
  readln(n);
  for i:=1 to n do read(a[i],b[i],space);
  if n=1 then ans('YES');
  if n=2 then if (a[1]=a[2]) or (b[1]=b[2]) then ans('YES') else ans('NO');
  st:=1; fn:=1; add(n,n-2,n-1,n);
  while st<>fn do
  begin
    out(x,y,z,w);
    if (x=2) then begin if (a[y]=a[z]) or (b[y]=b[z]) then ans('YES'); end else
    begin
      if (x=3) then
      begin
        if ((a[z]=a[w]) or (b[z]=b[w])) and (not used[2,y,w,1]) then add(2,y,w,1);
      end
        else
      begin
        if ((a[z]=a[w]) or (b[z]=b[w])) and (not used[x-1,x-3,y,w]) then add(x-1,x-3,y,w);
        if ((a[x-3]=a[w]) or (b[x-3]=b[w])) and (not used[x-1,w,y,z]) then add(x-1,w,y,z);
      end;
    end;
  end;
  ans('NO');
end.