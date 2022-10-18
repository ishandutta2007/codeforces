import Control.Monad
import Data.Int
import Data.Maybe
import Data.Ratio
import Text.Printf
import qualified Data.ByteString.Char8 as B

intLine :: IO [Integer]
intLine = fmap (map (fromIntegral . fst . fromJust . B.readInt) . B.words) B.getLine

main = do
    [n,w,v,u] <- intLine
    ts <- replicateM (fromIntegral n) $ do
        [x,y] <- intLine
        return $ x % v - y % u; 
    let t = if minimum ts >= 0 then 0 else max 0 (maximum ts)
    let res = t + w % u
    putStrLn $ printf "%.12f" $ (fromRational res :: Double)