var
  n,a,b,c,x,y,kol,ans,ost:longint;


begin

  readln(n,a,b,c);
   ans:=0;
  for x:=0 to n do
   for y:=0 to n do
    begin
     ost:=(n-((a*x)+(b*y)));
      if (ost>=0) and (ost mod c = 0)
       then
        begin
         kol:=x+y+(ost div c);
         if kol>ans then ans:=kol;
        end;
    end;
  writeln(ans);

end.