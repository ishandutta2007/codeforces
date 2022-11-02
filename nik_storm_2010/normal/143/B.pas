var
  s,ans : string;
   leng,i,kol1,j : longint;
    minus : boolean;


begin

  readln(s);
   if s[1] = '-' then begin delete(s,1,1); minus:=true; end else minus:=false;

  leng:=length(s); i:=1;
   while (i<=leng) and (s[i]<>'.') do inc(i);

  ans:='';
   if i>leng
    then
     begin

      i:=leng;
       kol1:=0;
        while i>=1 do
         begin

          ans:=s[i] + ans;
           inc(kol1);
            if (i<>1) and (kol1=3) then begin kol1:=0; ans:=',' + ans; end;
           dec(i);

         end;
       ans:=ans+'.00';

     end
    else
     begin

      j:=i; i:=i-1;
       kol1:=0;
        while i>=1 do
         begin

          ans:=s[i] + ans;
           inc(kol1);
            if (i<>1) and (kol1=3) then begin kol1:=0; ans:=',' + ans; end;
           dec(i);

         end;
       ans:=ans+'.';
       if j+1<=leng then ans:=ans+s[j+1] else ans:=ans+'0';
        if j+2<=leng then ans:=ans+s[j+2] else ans:=ans+'0';

     end;

   ans:='$' + ans;
  if minus = true then writeln('(',ans,')') else writeln(ans);


end.