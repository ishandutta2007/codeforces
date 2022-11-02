uses
  math;
var
  r1,r2,c1,c2,i,j:longint;
  have:boolean;

function check(x,y:longint):boolean;
begin
  if (1<=x) and (x<=8) and (1<=y) and (y<=8) then exit(true) else exit(false);
end;

begin
  readln(r1,c1,r2,c2);
  if (r1=r2) or (c1=c2) then write(1) else write(2);
  write(' ');
  if (odd(r1+c1)<>odd(r2+c2)) then write(0) else
  begin
    have:=false;
    i:=r1;
    j:=c1;
    while (true) do
    begin
      dec(i);
      dec(j);
      if (not check(i,j)) then break;
      if (i=r2) and (j=c2) then have:=true;
    end;
    i:=r1;
    j:=c1;
    while true do
    begin
      inc(i);
      dec(j);
      if (not check(i,j)) then break;
      if (i=r2) and (j=c2) then have:=true;
    end;
    i:=r1;
    j:=c1;
    while true do
    begin
      inc(i);
      inc(j);
      if (not check(i,j)) then break;
      if (i=r2) and (j=c2) then have:=true;
    end;
    i:=r1;
    j:=c1;
    while true do
    begin
      dec(i);
      inc(j);
      if (not check(i,j)) then break;
      if (i=r2) and (j=c2) then have:=true;
    end;
    if (have) then write(1) else write(2);
  end;
  write(' ');
  i:=abs(r1-r2);
  j:=abs(c1-c2);
  if (i>j) then writeln(i) else writeln(j);
end.