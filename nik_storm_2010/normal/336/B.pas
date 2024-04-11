var
  m,r,p:int64; ans,add:extended; i:longint;


function findl(i:int64):extended;
var res:extended;
begin
  if (i=1) then exit(0);
  if (i=2) then exit(r+r+sqrt(r*r+r*r));
  res:=r+sqrt(p*p+p*p);
  findl:=res*(i-2)+(r+r+p*(i-3))/2*(i-2)+r+r+sqrt(r*r+r*r);
end;


function findr(i:int64):extended;
var res:extended;
begin
  if (i=m) then exit(0);
  if (i=m-1) then exit(r+r+sqrt(r*r+r*r));
  res:=r+sqrt(p*p+p*p);
  findr:=res*(m-i-1)+(r+r+p*(m-i-2))/2*(m-i-1)+r+r+sqrt(r*r+r*r);
end;


begin
  readln(m,r); p:=r*2; ans:=0;
  for i:=1 to m do
  begin
    add:=findl(i)+findr(i)+p;
    ans:=ans+add;
  end;
  writeln((ans/(m*m)):0:6);
end.