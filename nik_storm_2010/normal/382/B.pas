var
  used:array[0..5000] of boolean;
  a,b,w,x,c,time,i,j,cycle,cnt,raz,d:int64;

begin
  readln(a,b,w,x,c);
  if (c<=a) then begin writeln(0); halt; end;
  i:=b;
  while (used[i]=false) do
  begin
    used[i]:=true;
    if (i>=x) then i:=i-x else i:=w-(x-i);
  end;
  j:=i;
  cycle:=0;
  cnt:=0;
  while (true) do
  begin
    if (cycle<>0) and (j=i) then break;
    inc(cycle);
    if (j>=x) then j:=j-x else
    begin
      j:=w-(x-j);
      inc(cnt);
    end;
  end;
  time:=0;
  while (b<>i) do
  begin
    if (c<=a) then begin writeln(time); halt; end;
    dec(c);
    inc(time);
    if (b>=x) then b:=b-x else
    begin
      b:=w-(x-b);
      dec(a);
    end;
  end;
  if (c<=a) then begin writeln(time); halt; end;
  raz:=cycle-cnt;
  d:=(c-a-1) div raz;
  c:=c-cycle*d;
  a:=a-cnt*d;
  time:=time+cycle*d;
  while (c>a) do
  begin
    dec(c);
    if (b>=x) then b:=b-x else
    begin
      dec(a);
      b:=w-(x-b);
    end;
    inc(time);
  end;
  writeln(time);
end.