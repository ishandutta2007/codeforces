uses math;
var
    n,m,x,y,a,b,nn,lx,ly,coef,x1,x2,y1,y2,l,r,dx,dy:int64;


function nod(a,b:int64):int64;
begin
  while (a>0) and (b>0) do
    if a>b then a:=a mod b else b:=b mod a;
  nod:=a+b;
end;


begin

  readln(n,m,x,y,a,b);
  nn:=nod(a,b); a:=a div nn; b:=b div nn;
  dx:=n div a; dy:=m div b; coef:=min(dx,dy);
  lx:=coef*a; ly:=coef*b;

  l:=lx div 2; r:=lx div 2;
  if lx mod 2=1 then inc(l);
  if x+r>n then begin x1:=n-lx; x2:=n; end else
  if x-l<0 then begin x1:=0; x2:=lx; end else begin x1:=x-l; x2:=x+r; end;

  l:=ly div 2; r:=ly div 2;
  if ly mod 2=1 then inc(l);
  if y+r>m then begin y1:=m-ly; y2:=m; end else
  if y-l<0 then begin y1:=0; y2:=ly; end else begin y1:=y-l; y2:=y+r; end;

  writeln(x1,' ',y1,' ',x2,' ',y2);

end.