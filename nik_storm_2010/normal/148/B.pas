var
 vp,vd,t,f,c,kol,vo:longint;
  i:extended;

begin
 readln(vp);
  readln(vd);
   readln(t);
  readln(f);
 readln(c);

 if vp>=vd
  then
   begin
    kol:=0;
   end
  else
   begin
    vo:=vd-vp;
     i:=t*vp; kol:=0;
      while true do
       begin
        if i>=c then break;
         i:=i+(i / vo)*vp;
          if i>=c then kol:=kol else inc(kol);
         i:=i+((i / vd)+f)*vp;
       end;
   end;
 writeln(kol);
end.